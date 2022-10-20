#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

double height(double Sx,double Sy,double Px,double Py,double x){
    return Sy  -  (Sy-Py)*(Sx-x)/(Sx-Px);
}
double dist(double x,double y){
    return sqrt(x*x+y*y);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int H;
    cin >> n >> H;
    vector<int> X(n),Y(n);
    vector<double> x(n);
    vector<double> y(n);
    rep(i,n){
        cin >> X[i] >> Y[i];
    }
    rep(i,n){
        x[i] = X[i];
        y[i] = Y[i];
    }
    double Sx = x[n-1];
    double Sy = y[n-1] + H;
    double Px = x[n-2];
    double Py = y[n-2];
    double res = dist(x[n-1]-x[n-2],y[n-1]-y[n-2]);
    for(int i=n-3;i>=0;i--){
        double Ax = x[i];
        double Ay = y[i];
        double Bx = x[i+1];
        double By = y[i+1];
        
        double Ah = height(Sx,Sy,Px,Py,Ax);
        double Bh = height(Sx,Sy,Px,Py,Bx);
        if(Ah > Ay && Bh>By){
            //    
        }else if(Ah>Ay&&Bh<=By){
            //  -> 
            double ok = Ax;//
            double ng = Bx;//
            rep(i,40){
                double mid = (ok+ng)/2;
                if(height(Sx,Sy,Px,Py,mid) >= height(Ax,Ay,Bx,By,mid)){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            res += dist(Bx-ok,By-height(Sx,Sy,Px,Py,ok));
        }else if(Ah<=Ay&&Bh>By){
            //  -> 
            double ng = Ax;//
            double ok = Bx;//
            rep(i,40){
                double mid = (ok+ng)/2;
                if(height(Sx,Sy,Px,Py,mid) >= height(Ax,Ay,Bx,By,mid)){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            res += dist(Ax-ok,Ay-height(Sx,Sy,Px,Py,ok));
        
        }else{
            //
            res += dist(Ax-Bx,Ay-By);
        
        }
        

        /// P
        if(height(Sx,Sy,Px,Py,Ax) < Ay){
            Px = Ax;
            Py = Ay;
        }
        if(height(Sx,Sy,Px,Py,Bx) < By){
            Px = Bx;
            Py = By;
        }
        // cerr << i << " " << Sx << " " << Sy << " " << Px << " " << Py << " " << res << endl;
    }
    cout << setprecision(30) << fixed <<  res << endl;
    return 0;
}