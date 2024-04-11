a, b = input().split()
c = int(input())

if c % 2 == 0:
    print("undefined")
else:
    if (a == '^' and b == '>') or (a == '>' and b == 'v') or (a == 'v' and b == '<') or (a == '<' and b == '^'):
        print("cw" if c % 4 == 1 else "ccw")
    else:
        print("ccw" if c % 4 == 1 else "cw")