#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
using namespace std;

int n;

string s[1007];

void wypisz()
{
    for(int i = 1; i <= n; ++i)
    {
        cout << s[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        if(s[i][0]=='O' && s[i][1]=='O')
        {
            s[i][0] = '+';
            s[i][1] = '+';
            cout << "YES" << endl;
            wypisz();
            return 0;
        }

        if(s[i][3]=='O' && s[i][4]=='O')
        {
            s[i][3] = '+';
            s[i][4] = '+';
            cout << "YES" << endl;
            wypisz();
            return 0;
        }
    }

    cout << "NO";
}