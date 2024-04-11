#include <iostream>

using namespace std;

int main() {
    int N;
    string word;
    cin >> N;
    int length = 0;
    int x = 0;
    int vol = 0;
    int ans = 0;
    while(length < N){
        if(x == 0){
        length++;
        }
        x=1;
        cin >> word;
        length+= word.length();
        for(int i = 0; i < word.length(); i++){
            if(word[i] - 'A' >= 0 && word[i] - 'A' < 26){
                vol ++;
                
            }
        }
        
        ans = max(ans, vol);
        vol = 0;
    }
    cout << ans;
}