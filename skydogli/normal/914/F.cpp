#include<bits/stdc++.h>
using namespace std;
#define MN 100005
char ch[MN],c[MN];
int q,n;
bitset<MN>st[26],tmp,fk;
int main(){
	scanf("%s%d",ch+1,&q);
	n=strlen(ch+1);
	for(int i=1;i<=n;++i){
		st[ch[i]-'a'][i]=1;
	}
	for(int i=1;i<=q;++i){
		int op,l,r;
		scanf("%d%d",&op,&l);
		if(op==1){
			scanf("%s",c);
			st[ch[l]-'a'][l]=0;
			st[c[0]-'a'][l]=1;
			ch[l]=c[0];
		}
		else{
			scanf("%d%s",&r,c);
			int len=strlen(c);
			r=r-len+1;
			tmp.set();
			for(int j=0;j<len;++j){
				tmp&=st[c[j]-'a']>>j;
			}
			fk.set();
			fk>>=(MN-(r-l+1));
			fk<<=l;
//			cerr<<tmp<<endl;
			printf("%d\n",(int)(tmp&fk).count());
		}
	}
	return 0;
}