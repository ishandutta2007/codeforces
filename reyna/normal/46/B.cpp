//In the name of God
#include <iostream>
#include <cmath>
using namespace std;
int arr[5];
string size[5];
int main(){
    size[0] = "S",size[1] = "M",size[2] = "L",size[3] = "XL",size[4] = "XXL";
    for(int i = 0; i < 5;i++)
        cin >> arr[i];
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        string S;
        cin >> S;
        int in = 0;
        for(int j = 0; j < 5;j++){
            if(S == size[j])
                in = j;
        }
        int best = 5,the = 0;
        for(int j = 0; j < 5;j++){
            if(arr[j])
                if(abs(j - in) <= best){
                    best = abs(j-in);
                    the = j;
                }
        }
        arr[the]--;
        cout << size[the] << "\n";
    }
    return 0;
}