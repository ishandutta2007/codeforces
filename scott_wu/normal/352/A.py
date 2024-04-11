import sys

n = int(raw_input())
arr = map (int, raw_input().split())

a = arr.count(5)
b = arr.count(0)

if b == 0:
    print -1
    sys.exit()

s = ""
for i in range (8, a, 9):
    #print i
    for j in range (9):
        s += str(5)

if a < 9:
    b = 1
for i in range (b):
    s += str(0)

print s