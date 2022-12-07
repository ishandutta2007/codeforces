#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,x,y;
string s,s1,s2,o;
map<string,int> mx,my;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	mx["void"]=1;
	my["void"]=1;
	mx["errtype"]=999999;
	my["errtype"]=1;
	for (int i=0;i<n;i++){
		cin >> o;
		if (o=="typedef"){
			cin >> s1 >> s2;
			s="";
			x=0;
			y=0;
			for (int i=0;i<s1.size();i++)if (s1[i]=='&')x++;else if (s1[i]=='*')y++;else s+=s1[i];
			if (my[s]==0)x+=999999;
			x+=mx[s];
			y+=my[s];
			if (x>y)x=999999;
			int l=min(x,y);
			x-=l;
			y-=l;
			mx[s2]=x+1;
			my[s2]=y+1;
		}else{
			cin >> s1;
			s="";
			x=0;
			y=0;
			for (int i=0;i<s1.size();i++)if (s1[i]=='&')x++;else if (s1[i]=='*')y++;else s+=s1[i];
			x+=mx[s];
			y+=my[s];
			int l=min(x,y);
			x-=l;
			y-=l;
			if (x>y||my[s]==0)puts("errtype");else{
				cout << "void";
				for (int i=0;i<y;i++)putchar('*');
				puts("");
			}
		}

	}
	return 0;
}