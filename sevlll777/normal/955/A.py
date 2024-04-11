from math import ceil
hh, mm = map(int, input().split())
H, D, C, N = map(int, input().split())
print(min(C*(ceil(H/N)), 4*C*1/5*ceil((D*(max(0, 60*20-60*hh-mm))+H)/N)))