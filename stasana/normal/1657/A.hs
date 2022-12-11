parseInt :: String -> Int
parseInt number = (read number) :: Int

readInt :: IO Int
readInt = do
    number <- getLine
    pure $ parseInt number

readIntArr :: IO [Int]
readIntArr = do
    numbers <- getLine
    pure $ map parseInt $ words numbers

isqrt :: Int -> Int
isqrt = floor . sqrt . fromIntegral

solveSingle :: IO()
solveSingle = do
    arr <- readIntArr
    let x = arr !! 0
    let y = arr !! 1
    if (x == 0 && y == 0)
        then
            print(0)
        else if (isqrt(x * x + y * y) * isqrt(x * x + y * y) == x * x + y * y)
            then print(1)
            else print(2)

solve :: Int -> IO ()
solve n = if (n == 0)
    then
        pure()
    else do
        solveSingle
        solve(n - 1)

main :: IO ()
main = do
    n <- readInt
    solve $ n