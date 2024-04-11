#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n;
char s[Maxn+5];
std::vector<std::pair<char,int> > lis_1,lis_2;
std::vector<std::pair<int,int> > ans;
void add_ch(std::vector<std::pair<char,int> > &lis,std::pair<char,int> v){
	if(lis.empty()){
		lis.push_back(v);
		return;
	}
	if(lis.back().first==v.first){
		lis.back().second+=v.second;
	}
	else{
		lis.push_back(v);
	}
}
void build_string(std::vector<std::pair<char,int> > &lis,char *s,int n){
	for(int i=n;i>0;i--){
		add_ch(lis,std::make_pair(s[i],1));
	}
}
void exchange(int len){
	int sum=0;
	std::pair<char,int> val_1=lis_1.back();
	lis_1.pop_back();
	for(int i=len-1;i>=0;i--){
		add_ch(lis_1,lis_2[(int)lis_2.size()-i-1]);
		sum+=lis_2[(int)lis_2.size()-i-1].second;
	}
	ans.push_back(std::make_pair(val_1.second,sum));
	for(int i=0;i<len;i++){
		lis_2.pop_back();
	}
	add_ch(lis_2,val_1);
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	build_string(lis_1,s,n);
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	build_string(lis_2,s,n);
	bool rev=0;
	if(lis_1.size()>lis_2.size()){
		std::swap(lis_1,lis_2);
		rev=1;
	}
	if(lis_1.back().first==lis_2.back().first){
		if((lis_2.size()-lis_1.size())%4==3){
			exchange((lis_2.size()-lis_1.size()+1)/2/2*2);
		}
		int num=(lis_2.size()-lis_1.size())/2/2*2+1;
		lis_1.push_back(std::make_pair(lis_2[lis_2.size()-num-1].first,0));
		exchange(num);
	}
	else if(lis_2.size()-lis_1.size()>2){
		exchange((lis_2.size()-lis_1.size()+1)/2/2*2+1);
	}
	while(lis_1.size()>1||lis_2.size()>1){
		exchange(1);
	}
	printf("%d\n",(int)ans.size());
	if(rev){
		for(int i=0;i<(int)ans.size();i++){
			std::swap(ans[i].first,ans[i].second);
		}
	}
	for(int i=0;i<(int)ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}