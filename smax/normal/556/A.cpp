#include <iostream>
#include <string>

using namespace std;

int main(void){
    int n, c;
    string s;
    
    cin>>n>>s;
    int o, z;
    o= z= 0;
    for(int i= 0; i<n; i++){
        if(s[i] == '1') o++;
        else z++;
    }
    
    cout<< n- 2*min(o, z) <<endl;
    
    return 0;
}