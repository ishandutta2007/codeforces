#include<iostream>
main(){int64_t x,t,z=1e18;std::cin>>x;t=z*9%x*9%x;std::cout<<x-t<<' '<<x-t+z-1;}