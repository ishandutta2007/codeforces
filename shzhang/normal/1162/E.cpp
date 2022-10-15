#include <cstdio>
#include <vector>

using namespace std;

int n;

bool solve(vector<int>& seq)
{
    vector<int> newseq;
    int one_cnt = 0;
    for (int i = 0; i < seq.size(); i++) {
        if (seq[i] > 1)
            newseq.push_back(seq[i]-1);
        else
            one_cnt++;
    }
    if (one_cnt) return one_cnt <= n/2;
    return solve(newseq);
}

int main()
{
    scanf("%d", &n);
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        int val; scanf("%d", &val); a.push_back(val);
    }
    printf(solve(a) ? "Alice" : "Bob");
    return 0;
}