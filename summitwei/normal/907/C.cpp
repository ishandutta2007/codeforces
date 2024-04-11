#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    //true = is a possibility, false = is not
    vector<bool> possibilities(26, true);
    vector<bool> shockedCases(26, false);
    vector<bool> noShockCases(26, true);
    int count = 0; //count is the amount of excessive shocks
    bool canGuess = false;

    //! = shock, . = noshock, ? = guess
    for(int k=0; k<N; k++){
        char C;
        cin >> C;
        if(C == '!'){
            if(canGuess){
                count++;
                string blah;
                cin >> blah;
            } else{
                string shocked;
                cin >> shocked;
                shockedCases.assign(26, false);
                for(int i=0; i<shocked.length(); i++){
                    //97 is conversion #
                    int thisOne = shocked[i]-97;
                    shockedCases[thisOne] = true;
                }
                
                int possCount = 0;
                for(int i=0; i<26; i++){
                    possibilities[i] = possibilities[i] && shockedCases[i];
                    if(possibilities[i] == true){
                        possCount++;
                    }
                }
                if(possCount == 1){
                    canGuess = true;
                }
            }
        } else if(C == '.'){
            if(canGuess){
                string blah;
                cin >> blah;
                continue;
            } else{
                string notShocked;
                cin >> notShocked;
                noShockCases.assign(26, true);
                for(int i=0; i<notShocked.length(); i++){
                    int thisOne = notShocked[i]-97;
                    noShockCases[thisOne] = false;
                }

                int possCount = 0;
                for(int i=0; i<26; i++){
                    possibilities[i] = possibilities[i] && noShockCases[i];
                    if(possibilities[i] == true){
                        possCount++;
                    }
                }
                if(possCount == 1){
                    canGuess = true;
                }
            }
        } else if(C == '?'){
            if(k == N-1){
                cout << count << "\n";
                return 0;
            } else{
                if(canGuess){
                    char blah;
                    cin >> blah;
                    count++;
                } else{
                    char shockChar;
                    cin >> shockChar;
                    int thisOne = shockChar-97;
                    possibilities[thisOne] = false;

                    int possCount = 0;
                    for(int j=0; j<26; j++){
                        if(possibilities[j] == true){
                            possCount++;
                        }
                    }
                    if(possCount == 1){
                        canGuess = true;
                    }
                }
            }
        }
    }

    cout << count << "\n";
    return 0;
}