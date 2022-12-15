#include <iostream>
#include <set>
#include<fstream>

using namespace std;

const int N = 5007;

int gn[N];

string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //freopen("output.txt", "w", stdout);
    
    cin >> s;
    
    gn[0] = 0;
    gn[1] = 1;
    gn[2] = 1;
    
    for(int i = 3; i <= s.size(); i++){
        set<int> mex;
        mex.insert(gn[i - 2]);
        for(int j = 0; j <= i - 3; j++){
            mex.insert(gn[j] ^ gn[i-3-j]);   
        }
        set<int> :: iterator it = mex.begin();
        
        gn[i] = 0;
        
        while(it != mex.end() && *it == gn[i]){
            it++;
            gn[i]++;  
        }
    }
    
    int curr = 0, res = 0;
    
    for(int i = 1; i < s.size() - 1; i++){
        if(s[i+1] == s[i-1]){
            curr++; 
        }
        else{
            res ^= gn[curr];
            curr = 0;   
        }
    }
    
    res ^= gn[curr];
    
    //cout << res << endl;
    
    if(!res){
        cout << "Second\n";
        
        return 0;
    }
    
    cout << "First\n";
    
    curr = 0;
    
    for(int i = 1; i < s.size() - 1; i++){
        if(s[i+1] == s[i-1]){
            curr++; 
        }
        else{
            
            if(curr >= 1){
                //cout << curr << " curr i " << i << endl;
                if((res ^ gn[curr] ^ gn[max(curr - 2, 0)]) == 0){
                    cout << i - curr + 1 << "\n";
                    
                    return 0;   
                }
                
                if(curr >= 3){
                    for(int j = 0; j < curr - 2; j++){
                        if((res ^ gn[j] ^ gn[curr - j - 3] ^ gn[curr]) == 0){
                            cout << i - curr + j + 2  << "\n";
                            
                            return 0;    
                        }
                    }
                }
            }
            
            curr = 0;   
        }
    }
    
    if(curr >= 1){
        int i = s.size() - 1;
         
        if((res ^ gn[curr] ^ gn[max(curr - 2, 0)]) == 0){
            cout << i - curr + 1 << "\n";
            
            return 0;   
        }
        
        if(curr >= 3){
            //cout << curr << " curr\n";
            //cout << gn[curr] << " " << res << endl;
            
            for(int j = 0; j < curr - 2; j++){
                if((res ^ gn[j] ^ gn[curr - j - 3] ^ gn[curr]) == 0){
                    //cout << gn[j] << " " << gn[curr - j - 3] << endl;
                    cout << i - curr + j + 2  << "\n";
                    
                    return 0;    
                }
            }
        }
    }
    
    //system("pause");
    
    return 0;
}
/*
aaaaaaa
*/