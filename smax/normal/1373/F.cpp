/*
                
                                      
                                              
                                
                          
                                
                                      
                                  
                                                
                            
                    
                          
                                        
                                
                        
                
      
                              
                                      
                              
                              
                            
                          
                                      
                                
                        
          
                
                            
                            
                                                    
                        
                
                          
                        
                        
                  
                        
                
            
          
          
          
              
              
  
  
  
    
    
  
  




*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        for (int i=0; i<n; i++)
            cin >> b[i];

        a.insert(a.end(), a.begin(), a.end());
        b.insert(b.end(), b.begin(), b.end());
        int pos = 0;
        bool ok = false;
        while (pos < n && !ok) {
            ok = true;
            int change = min(a[pos+n], b[pos+n]), last = 0;
            a[pos+n] -= change;
            for (int i=pos+1; i<pos+n; i++) {
                if (a[i] > b[i]) {
                    ok = false;
                    a[pos+n] += change;
                    a[i] += last;
                    pos = i;
                    break;
                }
                last = min(b[i] - a[i], a[i+1]);
                a[i+1] -= last;
            }
            if (ok && a[pos+n] != 0) {
                ok = false;
                pos += n;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}