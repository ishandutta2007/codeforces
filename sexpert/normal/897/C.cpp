#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

char respondQuery(long long n, long long k)
{
    // f0 has length 75
    // s1 has length 34
    // s2 has length 32
    // s3 has length 2
    // structure is fi = s1 + f(i - 1) + s2 + f(i - 1) + s3, hence fi has length 68 + 2*length(fi).
    // length(fi) + 68 = 2*(length(f(i - 1) + 68)
    // Hence if ai = length(fi) + 68 then a0 = 143, a(i + 1) = 2*ai, hence length(fi) = 143*2^i - 68
    //cout << "calling " << n << " " << k << endl;
    long long len = 143ll*(1ll << (n - 1)) - 68ll;
    //cout << len << endl;
    string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    string s1 = "What are you doing while sending \"";
    string s2 = "\"? Are you busy? Will you send \"";
    string s3 = "\"?";
    if(n == 0)
    {
        if(k > 75)
            return '.';
        return f0[k - 1];
    }
    if(k <= 34)
    {
        return s1[k - 1];
    }
    if(n > 54 || k <= 34ll + len)
    {
        return respondQuery(n - 1, k - 34);
    }
    if(k <= 66ll + len)
    {
        return s2[k - 35 - len];
    }
    if(k <= 66ll + 2ll*len)
    {
        return respondQuery(n - 1, k - len - 66);
    }
    if(k <= 68ll + 2ll*len)
    {
        return s3[k - 67 - 2*len];
    }
    return '.';
}

int main()
{
    long long q, n, k;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> n >> k;
        cout << respondQuery(n, k);
    }
    return 0;
}