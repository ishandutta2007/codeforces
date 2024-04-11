def gcf (a, b):
    return a if b == 0 else gcf (b, a % b)

def lcm (a, b):
    return a * b / gcf (a, b)

def solve (a, b):
    return a / b

x, y, a, b = (int(s) for s in raw_input().split())
print solve (b, lcm (x, y)) - solve (a - 1, lcm (x, y))