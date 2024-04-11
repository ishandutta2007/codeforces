#include<cstdio>
#include<cstring>

using namespace std;

int suma[200020][26],sumb[200020][26];
int len;
char A[200020],B[200020];

bool work(int la,int ra,int lb,int rb)
{
	int flag=0;
	for(int i=la;i<=ra;i++)
		if(A[i]!=B[lb+i-la])
		{
			flag=1;
			break;
		}
	if(!flag)return 1;
	if((ra-la+1)%2==1)return 0;
	for(int i=0;i<26;i++)
		if(suma[ra][i]-suma[la-1][i]!=sumb[rb][i]-sumb[lb-1][i])return 0;
	int mida=(la+ra)>>1,midb=(lb+rb)>>1;
	return (work(la,mida,lb,midb)&work(mida+1,ra,midb+1,rb))||(work(la,mida,midb+1,rb)&&work(mida+1,ra,lb,midb));
}

int main()
{
	scanf("%s",A+1);
	scanf("%s",B+1);
	len=strlen(A+1);
	for(int i=1;i<=len;i++)
		for(int j=0;j<26;j++)
			suma[i][j]=suma[i-1][j]+(A[i]==('a'+j)),sumb[i][j]=sumb[i-1][j]+(B[i]==('a'+j));
	if(work(1,len,1,len))puts("YES");
	else puts("NO");
}