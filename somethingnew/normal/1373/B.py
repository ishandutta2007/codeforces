def solve():
    s = input()
    z = 0
    o = 0
    for i in s:
        if i == "1":
            o += 1
        else:
            z += 1
    c = min(o,z)
    if c%2 == 0:
        print("NET")
    else:
        print("DA")
for i in range(int(input())):
    solve()