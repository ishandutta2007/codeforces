#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	if (c==0 && d!=0){
		cout<<"Ron"<<endl;
		return 0;
	}
	if (c!=0 && d!=0 && a==0 && b!=0){
		cout<<"Ron"<<endl;
		return 0;
	}
	if (c==0 && d!=0){
		cout<<"Ron"<<endl;
		return 0;
	}
	if (b*d*f>a*c*e) cout<<"Ron"<<endl;
				else cout<<"Hermione"<<endl;
    return 0;
}