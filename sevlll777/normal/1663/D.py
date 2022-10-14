s = input()
x = int(input())
if s == "ABC":
    if x <= 1999:
        print("YES")
    else:
        print("NO")
elif s == "ARC":
    if x <= 2799:
        print("YES")
    else:
        print("NO")
elif s == "AGC":
    if x >= 1200:
        print("YES")
    else:
        print("NO")
else:
    print(1 / 0)