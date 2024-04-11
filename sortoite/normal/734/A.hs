main = do
    n <- read `fmap` getLine :: IO Int
    s <- getLine
    let anton = length $ filter (=='A') s
    let danik = length $ filter (=='D') s
    if anton == danik then putStrLn "Friendship"
    else if anton > danik then putStrLn "Anton"
    else putStrLn "Danik"