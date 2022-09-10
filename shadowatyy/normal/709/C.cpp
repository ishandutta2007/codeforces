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
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
using namespace std;

string s;

bool res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s;

    for(int i = 0; i < s.size(); ++i)
    {
    	if(s[i]!='a')
    	{
    		res = 1;

    		for(int j = i; j < s.size(); ++j)
    		{
    			if(s[j]=='a')
    				break;

    			s[j]--;
    		}

    		break;
    	}
    }

    if(res)
		cout << s;
	else
	{
		s[s.size()-1] = 'z';

		cout << s;
	}

}