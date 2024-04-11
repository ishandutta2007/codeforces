#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int mp[6][4]={{1,2,3,4},{9,10,11,12},{5,6,7,8},{21,22,23,24},{13,14,15,16},{17,18,19,20}};
int c[30];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool check()
{
	bool jdg;
	for(int cur1,cur2,i=0; i<=5; i+=2)
	{
		jdg=0,cur1=c[mp[i][0]],cur2=c[mp[i+1][0]];
		rep(j,0,3)
		{
			if(c[mp[i][j]]!=cur1) {jdg=1; break;}
			if(c[mp[i+1][j]]!=cur2) {jdg=1; break;}
		}
		if(!jdg)
		{
			if(i==0)
			{
				rep(j,0,5)
					if(j!=i && j!=i+1)
						if(c[mp[j][0]]!=c[mp[j][1]] || c[mp[j][2]]!=c[mp[j][3]]) return 0;
				return c[5]==c[19] && c[17]==c[23] && c[21]==c[15] && c[13]==c[7] || c[5]==c[15] && c[13]==c[23] && c[21]==c[19] && c[17]==c[7];
			}
			if(i==2)
			{
				rep(j,0,5)
					if(j!=i && j!=i+1)
					{
						if(j==0 || j==1)
							if(c[mp[j][0]]!=c[mp[j][1]] || c[mp[j][2]]!=c[mp[j][3]]) return 0;
						if(j==4 || j==5)
							if(c[mp[j][0]]!=c[mp[j][2]] || c[mp[j][1]]!=c[mp[j][3]]) return 0;
					}
				return c[1]==c[14] && c[13]==c[9] && c[11]==c[19] && c[18]==c[3] || c[1]==c[17] && c[18]==c[9] && c[11]==c[14] && c[13]==c[3];
			}
			if(i==4)
			{
				rep(j,0,5)
					if(j!=i && j!=i+1)
						if(c[mp[j][0]]!=c[mp[j][2]] || c[mp[j][1]]!=c[mp[j][3]]) return 0;
				return c[1]==c[6] && c[5]==c[10] && c[9]==c[21] && c[22]==c[2] || c[1]==c[21] && c[22]==c[10] && c[9]==c[6] && c[5]==c[2];
			}
		}
	}
	return 0;
}

int main()
{
	rep(i,1,24) c[i]=getint();
	check()?puts("YES"):puts("NO");
	return 0;
}