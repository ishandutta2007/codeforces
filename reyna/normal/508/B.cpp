//In the name of God
#include <iostream>
using namespace std;
int main(){
    string S;
    cin >> S;
    int n = S.size();
    int last = -1;
    string P = "";
    for(int i = 0; i < n;i++){
        if((S[i] - '0') % 2 == 0){
            last = i;
            if(S[i] < S[n-1]){
                for(int j = 0; j < n-1;j++){
                    if(j != i)
                        P+= S[j];
                    else
                        P+=S[n-1];
                }
                P+=S[i];
                cout << P << endl;
                return 0;
            }
        }
    }
    if(last == -1){
        cout << last << endl;
        return 0;
    }
    int i = last;
    for(int j = 0; j < n-1;j++){
        if(j != i)
            P+= S[j];
        else
            P+=S[n-1];
    }
    P+=S[i];
    cout << P << endl;
    return 0;
}