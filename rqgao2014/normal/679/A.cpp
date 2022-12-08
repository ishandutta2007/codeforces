#include<bits/stdc++.h>
using namespace std;

string s;

inline bool get(int x){
	cout<<x<<endl;
	cin>>s;
	fflush(stdout);
	if(s[0]=='y') return 1; else return 0;
}
inline bool prime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}

int main(){
	for(int i=2;i<10;i++){
		if(!prime(i)) continue;
		if(get(i)){
			if(get(i*i)){
				puts("composite");
				return 0;
			}
			for(int j=i+1;j<=100/i;j++)
				if(prime(j)&&get(j)){puts("composite");return 0;}
			puts("prime");
			return 0;
		}
	}
	puts("prime");
	return 0;
}