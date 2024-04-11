#include <bits/stdc++.h>
#define maxn 500005
#define ll long long
#define mod 1000000007
using namespace std;
int m, k, n, s;
int a[maxn], b[maxn];
int cnt[maxn], nd[maxn];
int tt = 0;
int fst[maxn];
int fl[maxn];
int main()
{
	cin>>m>>k>>n>>s;
	for(int i = 1; i <= m; i++)
		cin>>a[i];
	int ss = 0;
	for(int i = 1; i <= s; i++)
	{
		cin>>b[i], 
		nd[b[i]]++;
		if(nd[b[i]] == 1) ss++;
	}
	int r = m - n * k;
	int npl = 1;
	for(int i = 1; i <= m; i++)
	{
		cnt[a[i]]++;
		if(cnt[a[i]] == nd[a[i]]) tt++;
		if(tt == ss)
		{
			while(1)
			{
				if(cnt[a[npl]] == nd[a[npl]]) break;
				cnt[a[npl]]--, npl++;
			}
			int n1 = (m - i) / k;
			n1 += min(i / k, (npl - 1) / k + 1);	
		
			if(n1 >= n && i >= k)
			{
				memset(cnt, 0, sizeof(cnt));
				int len1 = 0;
				for(int j = npl; j <= i; j++)
					if(cnt[a[j]] < nd[a[j]])
						fl[j] = 1, cnt[a[j]]++, len1++;	
			//	cout<<"!!!"<<i<<" "<<tt<<" "<<ss<<" "<<npl<<" "<<n1<<" "<<i<<" "<<len1<<endl;
				for(int j = npl; j <= i; j++)
					if(len1 < k && !fl[j])
						len1++, fl[j] = 1;
				while(len1 < k)
					fl[npl - 1] = 1, npl--, len1++;
				n--;
				while(n)
				{
					if(npl >= k + 1)
					{
						for(int s = npl - k; s <= npl - 1; s++)
							fl[s] = 1;
						npl -= k;
					}
					else
					{
						for(int s = i + 1; s <= i + k; s++)
							fl[s] = 1; 
						i += k;
					}
					n--;
				}
				cout<<r<<endl;
				for(int j = 1; j <= m; j++)
					if(!fl[j]) cout<<j<<" ";
				cout<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}