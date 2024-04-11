// In the name of God
#include <iostream>
using namespace std;
typedef long long ll;
ll n,x,y;
ll bs1(ll l,ll r,ll num){
    ll mid = (l+r)/2;
    if(r-l <= 0){
        return -1;
    }
    ll time = mid*x;
//  if(y*mid + ((time)/y)*x == num)
//      return -1;
//  if(time % y){
//      if(time+y-(time%y)<(mid+1)*x)
//          time+=y-(time%y);
//  }
    ll highnow = mid + ((mid*x+x-1)/y);
    ll lownow = mid + ((time)/y);
//  if(lownow == num)
//      return -1;
    if(highnow >= num && lownow < num){
        return mid;
    }
    if(highnow < num){
        return bs1(mid+1,r,num);
    }
    return bs1(l,mid,num);
    
}
ll bs2(ll l,ll r,ll num){
    ll mid = (l+r)/2;
    if(r-l <= 0){
        return -1;
    }
    ll time = mid*y;
//  if(x*mid + ((time)/x)*y == num)
//      return -1;
//  if(time % x){
//      if(time+x-(time%x)<(mid+1)*y)
//          time+=x-(time%x);
//  }
    ll highnow = mid + ((mid*y+y-1)/x);
    ll lownow = mid + ((time)/x);
//  if(lownow == num)
//      return -1;
    if(highnow >= num && lownow < num){
        return mid;
    }
    if(highnow < num){
        return bs2(mid+1,r,num);
    }
    return bs2(l,mid,num);
    
}
int main(){
    cin >> n >> x >> y;
    for(int i = 0; i < n;i++){
        ll num;
        cin >> num;
        ll ansy = bs1(0,num+1,num);
        ll ansx = bs2(0,num+1,num);
        if(ansy == -1 && ansx == -1){
            cout << "Both" << endl;
            continue;
        }
        if(ansx == -1){
            cout << "Vanya" << endl;
            continue;
        }
        if(ansy == -1){
            cout << "Vova" << endl;
            continue;
        }
        cout << "Both" << endl;
    }
}