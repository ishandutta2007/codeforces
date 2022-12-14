//In the name of God
#include <iostream>
using namespace std;
bool check(string S){
    for(int i = 0; i < S.size()/2;i++)
        if(S[i] != S[S.size()-i-1])
            return 0;
    return 1;
}
int main(){
    string S;
    cin >> S;
    for(int i = 0; i < S.size()+1;i++){
        for(int k = 0; k < 26;k++){
            string P = "";
            for(int j = 0; j < i;j++){
                P += S[j];
            }
            P += k + 'a';
            for(int j = i; j < S.size();j++){
                P+=S[j];
            }
            if(check(P)){
                cout << P << endl;
                return 0;
            }
        }
    }
    cout << "NA" << endl;
    return 0;
}