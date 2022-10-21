#include <iostream>

using namespace std;

int main() {
  int n,a,b;
  int c = 0;
  int num;
  int ans = 0;
  cin >> n >> a >> b;
  
  for(int i = 0; i < n; i++){
      cin >> num;
      if(num == 1){
          if(a != 0){
              a--;
          }
          else {
            if(b != 0){
                 
                  b--;
                  c++;
            }
            else {
               
                if(c!=0){
                     
                    c--; 
                }
                 else {
                    ans++;
                    
                }
            }
          }
      }
      if(num == 2){
        if(b == 0){
            ans += 2;
           
        }
        else {
            b--;
            
        }
      }
      
  }
  cout << ans;
}