#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<ctime>
using namespace std;
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define y1 gfdsgfdsg

int main(){
    int x,y;
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    cin>>x>>y;
    int ds=x*x+y*y;
    if (x==0 || y==0) {
            cout<<"black"<<endl;
            return 0;
        }
    for (int i=0;i<=2001;i++){
        if (ds==i*i){
            cout<<"black"<<endl;
            return 0;
        }
    }
    for (int i=0;i<=2001;i++){
        if (ds>i*i && ds<(i+1)*(i+1)){
            if ((x*y>0 && i%2==0)||(x*y<0 && i%2==1)){
                cout<<"black"<<endl;
                return 0;
            } else {
cout<<"white"<<endl;
                return 0;
            }
        }
    }
        return 0;
}