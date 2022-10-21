#include <bits/stdc++.h>
using namespace std;
pair<int,int> letters[26];
int lastletters[26];
int main(){
    int guestnum, guardnum;
    cin >> guestnum >> guardnum;
    string doors;
    int d = 0;
    int yesno = 0;
    cin >> doors;
    for(int i = 0; i < guestnum; i++){
        if(lastletters[doors[i] - 'A'] == 0){
            lastletters[doors[i] - 'A']  = 1;
            letters[doors[i] - 'A'].first = i + 1;
            letters[doors[i] - 'A'].second = i + 1;
        }
        else{
            letters[doors[i] - 'A'].second = i + 1;
        }
    }
    for(int i = 1; i <= guestnum; i++){
        for(int j = 0; j < 26; j++){
            if(i >= letters[j].first && i <= letters[j].second){
                d ++;
            }
        }
        if(d > guardnum){
            yesno = 1;
        }
        d = 0;
    }
    if(yesno == 0){
        cout << "NO";
    }
    else cout << "YES";
}