    #include<bits/stdc++.h>
    #include<chrono>
    #include<windows.h>
    #define rep(i,a,b) for(int i = a; i<b; i++)
    #define dep(i,a,b) for(int i = a; i>b; i--)
    #define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
    #define in(name, type) type name; cin >> name
    #define LOG(x, sep) std::cout << x << sep
    #define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
    #define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
    #define all(x) (x).begin(), (x).end()
    #define ll long long
    #define LSB(i) ((i) & -(i))
    #define MAXSIZE 200005
     
    using namespace std;
     
    int main() {
    	int t;
    	cin >> t;
    	rep(i, 0, t) {
    		int n;
    		cin >> n;
    		if (n < 4) {
    			cout << 4 - n << "\n";
     
    		}
    		else if (n % 2 == 0) {
    			cout << 0 << "\n";
    		}
    		else {
    			cout << 1 << "\n";
    		}
    	}
    	return 0;
    }