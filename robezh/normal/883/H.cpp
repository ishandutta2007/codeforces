#include <bits/stdc++.h>
using namespace std;

string str;
int t;
int ch[150];
vector<char> rem;
vector<char> good;


int main(){
    fill(ch, ch+150, 0);
    int n;
    cin >> n;
    getchar();
    getline(cin, str);
    for(int i = 0; i < n; i++) ch[str[i]]++;
    for(int i = 'A'; i <= 'Z'; i++){
        if(ch[i] % 2 == 1) rem.push_back(i);
        for(int j = 0; j < ch[i]/2; j++) good.push_back(i);
    }
    for(int i = 'a'; i <= 'z'; i++){
        if(ch[i] % 2 == 1) rem.push_back(i);
        for(int j = 0; j < ch[i]/2; j++) good.push_back(i);
    }
    for(int i = '0'; i <= '9'; i++){
        if(ch[i] % 2 == 1) rem.push_back(i);
        for(int j = 0; j < ch[i]/2; j++) good.push_back(i);
    }
    t = rem.size();

    if(t == 0){
        cout << 1 << endl;
        for(int j = 0; j < n/2; j++){printf("%c", good[j]);}
        for(int j = n/2-1; j >= 0; j--){printf("%c", good[j]);}
        return 0;
    }

    while(t < n){
        if(n % t == 0 && (n/t) % 2 == 1) break;
        t++;
    }
    cout << t << endl;
    while(rem.size() < t){
        rem.push_back(good.back());
        rem.push_back(good.back());
        good.pop_back();
    }
    for(int i = 0; i < t; i++){
        for(int j = good.size()-(n/t)/2; j < good.size(); j++){printf("%c", good[j]);}
        printf("%c", rem[i]);
        for(int j = (n/t)/2-1; j >= 0; j--){printf("%c", good.back());good.pop_back();}
        printf(" ");
    }


}