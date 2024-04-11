#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int happy[5][5];

int main(){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> happy[i][j];
    
    int stud[5];
    for(int i=0; i<5; i++)
        stud[i] = i;
       
    int ans = 0; 
    do{
        int cand = 0;
        for(int i=0; i<5; i++)
            for(int j=i; j+1<5; j+=2)
                cand += happy[ stud[j] ][ stud[j+1] ] + happy[ stud[j+1] ][ stud[j] ];
        ans = max(ans, cand);
        
    }while( next_permutation(stud,stud+5) );
    cout << ans << endl;
    
    return 0;
}