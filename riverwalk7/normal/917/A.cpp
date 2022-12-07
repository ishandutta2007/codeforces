#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define FOR(i,x,y) for(int i=x; i<=y; i++)

const int mod=int(1e9+7),MAXN=int(2e5+1);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;

    cin >> s;

    int n=s.length()-1,rez=0;

    FOR(i,0,n-1)
    {
        int t=0,zp=0;
        FOR(j,i,n)
        {
            if (s[j]=='?')
                zp++;
            else
                t+=s[j]=='('?1:-1;
            if (t<zp && zp>0)
            {
                t++;
                zp--;
            }
            else
                if (t<0)
                    break;

            if ((t==zp || (zp>t && (zp-t)%2==0)))
                rez++;
        }
    }

    cout << rez;

    return 0;
}