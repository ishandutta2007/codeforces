#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

template< int BASE, int MD >
class
HashTree
{
    int fundLen;
    vector< int > powers;
    vector< int > tree;
public:
    HashTree(int len) 
    {
        fundLen = 2;
        while (fundLen < len) {
            fundLen *= 2;
        }
        tree.assign(2 * fundLen, 0);
        powers.resize(fundLen + 1, 1);
        for (int i = 1; i <= fundLen; ++i) {
            powers[i] = 1ll * powers[i - 1] * BASE % MD;
        }
    }
    void
    updVal(int pos) // 0-based indexing
    {
        int curAdd = powers[pos];
        pos += fundLen;
        while (pos != 0) {
            addVal(tree[pos], curAdd);
            pos /= 2;
        }
    }
    int
    operator()(int from, int to) const // [from, to)
    {
        return 1ll * getHashNonRec(from, to) * powers[fundLen - from] % MD;
    }
private:
    void
    addVal(int &dst, int src) const
    {
        dst += src;
        while (dst >= MD) {
            dst -= MD;
        }
    }
    int
    getHashNonRec(int from, int to) const
    {
        int res = 0;
        from += fundLen;
        to += fundLen - 1;
        while (from < to) {
            if (from % 2 == 1) {
                addVal(res, tree[from]);
            }
            if (to % 2 == 0) {
                addVal(res, tree[to]);
            }
            from = (from + 1) / 2;
            to = (to - 1) / 2;
        }
        if (from == to) {
            addVal(res, tree[from]);
        }
        return res;
    }
};

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< int > p((istream_iterator< int >(cin)), istream_iterator< int >());
    HashTree< 1000003, 1000000007 > hash1(p.size()), revHash1(p.size());
    HashTree< 124247, 1000000009 > hash2(p.size()), revHash2(p.size());
    bool ok = false;
    for (int i = 0; i < n && !ok; ++i) {
        int pos = p[i] - 1;
        int halfLen = min(n - pos - 1, pos);
        int fromSt = pos, toSt = pos + halfLen;
        int fromRev = n - 1 - pos, toRev = n - 1 - pos + halfLen;
        if (hash1(fromSt, toSt + 1) != revHash1(fromRev, toRev + 1)
                || hash2(fromSt, toSt + 1) != revHash2(fromRev, toRev + 1)) {
            ok = true;
        }
        hash1.updVal(pos);
        hash2.updVal(pos);
        revHash1.updVal(n - 1 - pos);
        revHash2.updVal(n - 1 - pos);
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}