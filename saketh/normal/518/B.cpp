#include <iostream>
using namespace std;

string targ, news;

int tu[26], tl[26];
int nu[26], nl[26];

int main(){
    cin >> targ >> news;

    for(char c : targ){
        if('a' <= c && c <= 'z')
            tl[c-'a']++;
        else
            tu[c-'A']++;
    }

    for(char c : news){
        if('a' <= c && c <= 'z')
            nl[c-'a']++;
        else
            nu[c-'A']++;
    }

    int Y = 0, W = 0;

    for(int i=0; i<26; i++){
        int dem = 0, sur = 0;
        if(tl[i] <= nl[i]){
            Y += tl[i];
            sur += nl[i] - tl[i];
        }
        else{
            Y += nl[i];
            dem += tl[i] - nl[i];
        }
    
        if(tu[i] <= nu[i]){
            Y += tu[i];
            sur += nu[i] - tu[i];
        }    
        else{
            Y += nu[i];
            dem += tu[i] - nu[i];
        }

        W += min(dem, sur);
    }

    cout << Y << " " << W << endl;
}