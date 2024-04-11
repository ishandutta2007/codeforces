#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
typedef unsigned long long int li;
struct point{
    int x,y,z;
    point(){}
    point(int xx,int yy,int zz){
        x=xx;
        y=yy;
        z=zz;
    }
    long double abs(){
        return sqrt((long double)(x*x+y*y+z*z));
    }
    point operator -(point a){
        return point(x-a.x,y-a.y,z-a.z);
    }
};
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    point pts[5005];
    long double mdls[5005];
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pts[i]=point(a-x,b-y,c-z);
        mdls[i]=pts[i].abs();
    }
    long double mn;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            long double r=mdls[i]+mdls[j]+(pts[i]-pts[j]).abs();
            if((i==0 && j==1)|| r<mn){
                mn=r;
            }
        }
    }
    printf("%.10lf",mn/2);
    return 0;
}