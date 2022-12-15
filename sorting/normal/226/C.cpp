#include <bits/stdc++.h>

using namespace std;

long long l, r, mod, k;

struct mat 
{
    long long a, b, c;

    mat () 
    {
        a = 0;
        b = 1; 
        c = 1;
    }

    mat operator * (mat& dr)const 
    {
        mat ret;
        ret.a = a*dr.a + b*dr.b;
        ret.a %= mod;
        ret.b = a*dr.b + b*dr.c;
        ret.b %= mod;
        ret.c = b*dr.b + c*dr.c;
        ret.c %= mod;

        return ret;
    }
};

long long getFib(long long x) 
{
    mat ans = mat(), mult = mat();
    while(x) 
    {
        if(x%2) 
        {
            ans = ans*mult;
        }
        mult = mult*mult;
        x /= 2;
    }

    return ans.a;
}

long long g(long long x) 
{
    return r/x-l/x;
}

vector<long long> divs, nums;

int main ()
{
    cin >> mod >> l >> r >> k;
    l--;

    for(long long i = 1; i*i <= r; i++) 
    {
        long long  x1 = r/i;
        long long  x2 = r/(r/i);

        divs.push_back(x1);
        divs.push_back(x2);
    }
    sort(divs.begin(), divs.end());

    for(long long  i = 0; i < divs.size(); i++) 
    {
        if(g(divs[i]) < k) 
        {
            cout << getFib(divs[i-1]) << "\n";
            
            return 0;
        }
    }

    return 0;
}