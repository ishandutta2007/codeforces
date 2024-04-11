#include<iostream>
#include<string>
using namespace std;

string S;
int N, V, f;
int q[26];
int r[26];

int main(){
    cin >> S >> N;
    for(int c=0; c<S.length(); c++){
        if(q[S[c]-'a'] == 0) V++;
        q[S[c]-'a']++;
    }
    
    if(V > N){
        cout << "-1" << endl;
        return 0;
    }
    
    for(int c=0; c<26; c++)
        if(q[c]>0){
            f = c;
            break;
        }
    
    for(int c=0; c<26; c++)
        if(q[c]>0){
            r[c]++;
            N--;
        }
    
    for(; N; N--){
        int i=f, m=(q[f] + r[f] - 1)/r[f];
        for(int c=0; c<26; c++){
            if(q[c] == 0) continue;
            if((q[c] + r[c] - 1)/r[c] > m){
                m = (q[c] + r[c] - 1)/r[c];
                i = c;
            }
        }
            
        r[i]++;
        //N--;
    }
    
    int m = (q[f] + r[f] - 1)/r[f];
    for(int c=0; c<26; c++){
            if(q[c] == 0) continue;
            if((q[c] + r[c] - 1)/r[c] > m){
                m = (q[c] + r[c] - 1)/r[c];
            }
        }
    cout << m << endl;
    
    for(int c=0; c<26; c++)
        for(int z=0; z<r[c]; z++)
            cout << (char)('a'+c);
    cout << endl;
    return 0;
}