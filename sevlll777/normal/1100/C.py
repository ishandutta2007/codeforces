from math import sin, pi
n, r = map(int, input().split())
alpha = 360/n
s1 = sin(pi*alpha/180)
s2 = sin(pi*((180-alpha)/2)/180)
print(r*s1/(2*s2-s1))