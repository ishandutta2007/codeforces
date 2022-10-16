from sys import *

st=set(input().split())
n=int(input())
for j in st:
    stdout.write(j+" ")
stdout.write("\n")
for i in range(n):
    p=input().split()
    st.discard(p[0])
    st.add(p[1])
    for j in st:
        stdout.write(j+" ")
    stdout.write("\n")