from math import sqrt

def get_square_numbers(n):
    i = 1
    count = 0
    while i * i <= n:
        count += 1
        i += 1
    return count

def get_cube_numbers(n):
    i = 1
    count = 0
    while True:
        p = i * i * i
        if p <= n:
            count += 1
            i += 1
        else:
            return count

def get_solution(n):
    squares = get_square_numbers(n)
    cubes = get_cube_numbers(n)
    return squares + cubes - get_cube_numbers(sqrt(n))

t = int(input())

for i in range(t):
    n = int(input())
    print(get_solution(n))