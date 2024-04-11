#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0, f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int M = 1024, MOD = 1000000007;
char str[M*M];
string ans[M];
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
	#endif

	int n = read(), l = read(), k = read();
	scanf("%s", str);
	sort(str, str+n*l);
	int str_pos = 0, start_pos=0;
	for(int floor=0; floor<l; ++floor)
	{
		for(int i=start_pos; i<k; ++i)
		{
			//printf("start_pos=%d\n",start_pos );
			if(!str_pos || str[str_pos]!=str[str_pos-1])
				start_pos = i;
			ans[i].push_back(str[str_pos++]);
		}
	}
	// for(int i=0; i<n; ++i)
	// 	cout << ans[i] << "\n";
	for(int floor=0; floor<l; ++floor)
	{
		for(int i=0; i<n; ++i) 
			if((int)ans[i].size()==floor)
				ans[i].push_back(str[str_pos++]);
	}
	for(int i=0; i<n; ++i)
		cout << ans[i] << "\n";

	return 0;
}