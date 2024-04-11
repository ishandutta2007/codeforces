//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, i, j, ans = 0;
    cin>>n;
    n = abs(n);
    for(i=1,j=1;n!=0&&ans==0;j+=(++i))
    {
    	if(j == n || (j > n && (j - n) % 2 == 0))
    	{
    		ans = i;
		}
	}
	cout<<ans<<endl;
    return 0;
}