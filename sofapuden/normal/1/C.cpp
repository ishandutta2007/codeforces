#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double pi = 3.14159265359; 

double gcd(double x, double y) 
{ 
    return fabs(y) < 1e-4 ? x : gcd(y, fmod(x, y)); 
} 
  
void solve() 
{ 
	double Ax, Ay, Bx, By, Cx, Cy;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
    double a, b, c, Radius, Angle_A, Angle_B, Angle_C, semiperimeter, n, area; 
    a = sqrt((Bx - Cx) * (Bx - Cx) + (By - Cy) * (By - Cy)); 
    b = sqrt((Ax - Cx) * (Ax - Cx) + (Ay - Cy) * (Ay - Cy)); 
    c = sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By)); 
    semiperimeter = (a + b + c) / 2; 
    double area_triangle = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c)); 
  
    Radius = (a * b * c) / (4 * area_triangle); 
   
    Angle_A = acos((b * b + c * c - a * a) / (2 * b * c)); 
    Angle_B = acos((a * a + c * c - b * b) / (2 * a * c)); 
    Angle_C = acos((b * b + a * a - c * c) / (2 * b * a)); 
  
    n = pi / gcd(gcd(Angle_A, Angle_B), Angle_C); 

    area = (n * Radius * Radius * sin((2 * pi) / n)) / 2; 
  
    printf("%.7f\n", area); 
} 
  
int main() 
{ 
	std::ios::sync_with_stdio(0); std::cin.tie(0);
    solve();
    return 0; 
}