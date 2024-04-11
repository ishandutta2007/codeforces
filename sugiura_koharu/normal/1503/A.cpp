#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string s,ans1="",ans2="";
		int now=0,cnt=0,qwq=0,flag=1,x=0,y=0;
		cin >> s;
		s=' '+s;
		for(auto t:s) if(t=='1') ++qwq;
		if(qwq&1)
		{
			puts("NO");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(cnt<qwq/2)
				{
					ans1+='(';
					ans2+='(';
					++x,++y,++cnt;
				}
				else
				{
					ans1+=')';
					ans2+=')';
					--x,--y;
					if(x<0||y<0) flag=0;
				}
			}
			else
			{
				if(now)
				{
					ans1+='(';
					ans2+=')';
					++x,--y;
				}
				else
				{
					ans1+=')';
					ans2+='(';
					--x,++y;
				}
				if(x<0||y<0) flag=0;
				now^=1;
			}
		}
		if(!flag) puts("NO");
		else
		{
			cout << "YES\n" << ans1 << "\n" << ans2 << "\n";
		}
	}
	return 0;
}