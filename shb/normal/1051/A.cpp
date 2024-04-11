#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T,N;
char s[100010];

//0 lo 1 up 2 di
char gao(int x)
{
	if (x == 0) return 'a';
	if (x == 1) return 'A';
	return '1';
}

char tp(char c)
{
	if (c >= 'a' && c <= 'z') return 0;
	if (c >= 'A' && c <= 'Z') return 1;
	return 2;
}

bool ok()
{
	int v = 0;
	for (int i=1;i<=N;i++)
	v |= (1 << tp(s[i]));
	return (v == 7);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s + 1);
		N = strlen(s + 1);
		if (ok()) goto END;
		for (int i=1;i<=N;i++)
			for (int j=0;j<3;j++)
			{
				char tmp = s[i];
				s[i] = gao(j);
				if (ok())
				{
					goto END;
				}
				s[i] = tmp;
			}
		for (int i=1;i<=N;i++)
			for (int k=i+1;k<=N;k++)
				for (int j=0;j<3;j++)
					for (int l=j+1;l<3;l++)
					{
						char tmp1 = s[i], tmp2 = s[k];
						s[i] = gao(j);
						s[k] = gao(l);
						if (ok())
						{
							goto END;
						}
						s[i] = tmp1;
						s[k] = tmp2;
					}
		for (int i=1;i<=3;i++)
			s[i] = gao(i-1);
		END:
		printf("%s\n",s + 1);
	}
}