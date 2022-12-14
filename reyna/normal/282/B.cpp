//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    string ans = "";
    int fst = 0;
    int scn = 0;
    for(int i = 0; i < n;i++){
        int a,b;
        cin >> a >> b;
        if(fst + a <= scn + 500){
            fst += a;
            ans+='A';
        }else{
            scn += b;
            ans+='G';
        }
    }
    cout << ans << endl;
    return 0;
}