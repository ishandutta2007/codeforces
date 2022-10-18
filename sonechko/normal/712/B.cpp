#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 100000+10;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
//#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
int use[N];
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    string s;
    cin>>s;
    int l=0,r=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='R') l++; else
        if (s[i]=='L') l--;
        if (s[i]=='D') r++;
        if (s[i]=='U') r--;
    }
    int ans=0;
    for (int i=0; i<s.size(); i++)
    {
        if (l<-1&&s[i]=='L')
        {
            l+=2;
            s[i]='R';
            ans++;
            use[i]=1;
        }
        if (l>1&&s[i]=='R')
        {
            l-=2;
            s[i]='L';
            ans++;
            use[i]=1;
        }
        if (r<-1&&s[i]=='U')
        {
            r+=2;
            s[i]='D';
            ans++;
            use[i]=1;
        }
        if (r>1&&s[i]=='D')
        {
            r-=2;
            s[i]='U';
            ans++;
            use[i]=1;
        }
    }
    for (int i=0; i<s.size(); i++)
    {
        if (use[i]==1&&l==1&&r==1&&(s[i]=='D'||s[i]=='R'))
        {
            l=0;
            r=0;
        }
        if (use[i]==1&&l==1&&r==-1&&(s[i]=='U'||s[i]=='R'))
        {
            l=0;
            r=0;
        }
        if (use[i]==1&&l==-1&&r==1&&(s[i]=='D'||s[i]=='L'))
        {
            l=0;
            r=0;
        }
        if (use[i]==1&&l==-1&&r==-1&&(s[i]=='U'||s[i]=='L'))
        {
            l=0;
            r=0;
        }
    }

 for (int i=0; i<s.size(); i++)
    {
        if (use[i]==1&&l==1&&r==1&&(s[i]=='D'||s[i]=='R'))
        {
            l=0;
            r=0;
        }
        if (use[i]==1&&l==1&&r==-1&&(s[i]=='U'||s[i]=='R'))
        {
            l=0;
            r=0;
        }
        if (use[i]==1&&l==-1&&r==1&&(s[i]=='D'||s[i]=='L'))
        {
            l=0;
            r=0;
        }
        if (use[i]==1&&l==-1&&r==-1&&(s[i]=='U'||s[i]=='L'))
        {
            l=0;
            r=0;
        }
    }
     for (int i=0; i<s.size(); i++)
    {
        if (use[i]==0&&l==1&&r==1&&(s[i]=='D'||s[i]=='R'))
        {
            l=0;
            ans++;
            r=0;
        }
        if (use[i]==0&&l==1&&r==-1&&(s[i]=='U'||s[i]=='R'))
        {
            l=0;
            r=0;
            ans++;
        }
        if (use[i]==0&&l==-1&&r==1&&(s[i]=='D'||s[i]=='L'))
        {
            l=0;
            r=0;
            ans++;
        }
        if (use[i]==0&&l==-1&&r==-1&&(s[i]=='U'||s[i]=='L'))
        {
            l=0;
            r=0;
            ans++;
        }
    }
    if (l==0&&r==0)cout<<ans<<endl;
    else cout<<-1<<endl;
}