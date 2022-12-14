#include <iostream>
using namespace std;
long long oo = 1000*1000*1000+1;
int main(){
    int n;
    long long minx=oo,miny=oo,maxx=(-1)*oo,maxy=(-1)*oo;
    cin >> n;
    for(int i = 0; i < n;i++){
        long long x,y;
        cin >> x >> y;
        minx = min(x,minx);
        miny = min(y,miny);
        maxx=max(x,maxx);
        maxy = max(y,maxy);
    }
    long long tmp = max(maxx-minx,maxy-miny);
    cout << tmp*tmp << endl;
}