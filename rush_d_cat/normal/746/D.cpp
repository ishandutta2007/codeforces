#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int NICO = 100005;
char s[NICO];
int cnt[NICO];
int main()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    if(a < b)
    {
        for(int i=1;i<=a;i++)
        {
            if(b-k < (a+1-i))
            {
                cnt[i] = 1;
                b -= 1;
            } else {
                cnt[i] = k;
                b -= k;
            }
        }
        cnt[a+1] = b;
        if(b<0||b>k) 
        {
            cout <<"NO"<<endl;
            return 0;
        }
        for(int i=1;i<=a+1;i++)
        {
            //cout << i << "->" << cnt[i] << endl;
            for(int j=1;j<=cnt[i];j++) cout << "B";
            if(i!=a+1)cout << "G";
        }
    } else
    if(a > b)
    {
        for(int i=1;i<=b;i++)
        {
            if(a-k < (b+1-i))
            {
                cnt[i] = 1;
                a-=1;
            } else {
                cnt[i] = k;
                a-=k;
            }
        }
        cnt[b+1] = a;
        if(a<0||a>k)
        {
            cout << "NO" << endl;
            return 0;
        }
        for(int i=1;i<=b+1;i++)
        {
            for(int j=1;j<=cnt[i];j++) cout << "G";
            if(i!=b+1)cout << "B";
        }
    } else
    if(a==b)
    {
        for(int i=1;i<=n;i++)
        {
            if(i%2) cout << "G";
            else cout << "B";
        }
    }
}
/*
b a+1
k
*/