#include <iostream>
#include <stack>
using namespace std;
int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n; cin >> n;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    int nums[a];
    for(int j=0; j<a; j++){
      cin >> nums[j];
    }
    int minplace = 1;
    int maxplace = 1;
    for(int j=0; j<a; j++){
      if(nums[j]==1){
        minplace = j;
      }
      else if(nums[j]==a){
        maxplace = j;
      }

    }
    int ans = 0;
    bool sus = false;
    int x;
    int y;
    if(minplace>maxplace){
      x = a - (minplace);
      y = maxplace + 1;
      //cout << x << " " << y << '\n';

    if(x < y){
      ans = x;
      sus = true;
    }
    else{
      ans = y;
    }
    
    if(sus==true){
      if((minplace+1)-y < y){
        ans += (minplace+1)-y;
      }
      else{
        ans += y;
      }
    }
    else {
      if((minplace+1)-y < x){
        ans += (minplace+1)-y;
        
      }
      else{
        ans += x;
      }
    }
    }
    else{
    x = (minplace+1);
    y = a-(maxplace);

    //cout << x << " " << y << '\n';

    if(x < y){
      ans = x;
    }
    else{
      ans = y;
      sus = true;
    }
    
    if(sus==true){
      if((maxplace+1)-x < x){
        ans += (maxplace+1)-x;
      }
      else{
        ans += x;
      }
    }
    else{
      if((maxplace+1)-x < y){
        ans += (maxplace+1)-x;
      }
      else{
        ans += y;
      }
    }
    }

    if(a==2 || a==3){
      cout << 2 << '\n';
    }
    else {
    cout << ans << '\n';
    }
  }

}