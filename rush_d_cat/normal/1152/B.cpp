#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int x;
vector<int> ans;
void upd(){
    //cout<<x<<endl;
    int t=0;
    for(int i=0;;i++){
        if(x>>i&1) {
            ans.push_back(t); x=x^((1<<t)-1); 
            int y=x+1;
            while(y%2==0) y/=2;
            if(y==1) {
                printf("%d\n", 2*(int)ans.size()-1);
                for(auto x: ans) printf("%d ", x);
                exit(0);
            }
            x++; return;
        }
        t++;
    }
}
int main() {
    cin>>x;
    if(x==0) {
        return !printf("0\n");
    }
    while(1) upd();
}