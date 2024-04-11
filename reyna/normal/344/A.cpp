#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int last;
    int group = 1;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
    //  cout << a[1] << " " << last << endl;
        if(i == 0 && a[1] == '1'){
            last = 1;
        }else if(i == 0 && a[1] == '0'){
            last = 0;
        }
        else if(last == 1 && a[1] == '0'){
            group++;
            last = 0;
        }else if(last == 0 && a[1] == '1'){
            group++;
            last = 1;
        }
    }
    cout << group;
    return 0;
}