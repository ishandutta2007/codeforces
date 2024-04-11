#include <iostream>
using namespace std;
long long x1,x2,y1,y2,a,b,c,n,an;
int main(){
    cin>>x1>>y1>>x2>>y2>>n;
    while(n--){
        cin>>a>>b>>c;
        if(a*x1+b*y1+c>0 != a*x2+b*y2+c>0)an++;
    }
    cout<<an;
    return 0;
}