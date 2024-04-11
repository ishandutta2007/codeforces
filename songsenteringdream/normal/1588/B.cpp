#include<iostream>
#include<cmath>
using namespace std;
int T,L,R,md,I,J,K;long long sm,z,al,ar;
inline long long query(int l,int r){
	long long res;
	cout<<"? "<<l<<" "<<r<<endl;
	cin>>res;
	return res;
}
inline int calc(long long num){
	int len=sqrt(num*2)-5;
	for(len=max(len,0);len*(len-1ll)/2<num;++len);
	if(len*(len-1ll)/2>num) return 0;
	return len;
}
int main(){
	for(cin>>T;T--;){
		for(L=1,cin>>R,sm=query(L,R);1;){
			if(!(z=query(md=L+R>>1,R))){R=md;continue;}
			if(z==sm){L=md;continue;}
			al=query(L,md);ar=query(md,R);
			if(calc(al)&&query(md-calc(al)+1,md)==al){
				I=md-calc(al)+1;
				for(int l=I,r=J=R,md;l<r;J=l){
					md=(l+r>>1)+1;
					if(query(I,md)==(md-I)*(md-I+1ll)/2) l=md;
					else r=md-1;
				}
				K=J+calc(sm-(J-I)*(J-I+1ll)/2);
			}
			else{
				K=md+calc(ar)-1;
				for(int l=L,r=J=K,md;l<r;J=l){
					md=l+r>>1;
					if(query(md+1,K)==(K-md)*(K-md-1ll)/2) r=md;
					else l=md+1;
				}
				I=J+1-calc(sm-(K-J)*(K-J-1ll)/2);
			}
			cout<<"! "<<I<<" "<<J+1<<" "<<K<<endl;
			break;
		}
	}
	return 0;
}