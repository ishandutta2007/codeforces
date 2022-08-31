#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int ok = 1, i, j, n, m;
	cin>>n; cin>>m;

	char prev = ' ';

	while(n--)
	{
		string s;
		cin>>s;
		if(s[0]==prev){ ok=0; break; }
		for(j=1;j<m;j++) if(s[j]!=s[0]){ ok=0; break; }
		if(!ok) break;				
		prev = s[0];		
	}

	puts(ok?"YES":"NO");

	return 0;
}