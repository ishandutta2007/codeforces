n, m = map(int, raw_input().split())

a = map(int, raw_input().split())
b = map(int, raw_input().split())

a.sort()
b.sort()

aval, bval = 0, 0
while aval < len(a):
    while bval < len(b) and b[bval] < a[aval]:
        bval += 1
    if bval == len(b):
        break
    aval += 1
    bval += 1

print n - aval